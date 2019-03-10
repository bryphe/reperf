module Config = Config;
module Options = Options;

module type Args = {let config: Config.t;};

module Make = (Config: Args) => {
  open Pastel;

  module Benchmark = {
    type benchmarkFunction = unit => Result.t;

    type t = {
      name: string,
      f: benchmarkFunction,
    };
  };

  let _benchmarks: ref(list(Benchmark.t)) = ref([]);

  let _getTime = Unix.gettimeofday;

  type setupFunction('a) = unit => 'a;
  type testFunction('a) = 'a => unit;

  /* let defaultSetupFunction: setupFunction(unit) = () => (); */

  let bench =
      (~name: string, ~setup:setupFunction('a), ~f: testFunction('a), ~options=Config.config.options, ()) => {
    let newCase = () => {
      let opts = options;
      let iter = () => {
        /* Garbage collect to clear out env */

        let setupValue = setup();

        Gc.full_major();
        let beforeState = Gc.quick_stat();
        let startTime = _getTime();
        let count = ref(0);
        while (count^ < opts.iterations) {
          f(setupValue);
          count := count^ + 1;
        };
        let endTime = _getTime();

        let afterState = Gc.quick_stat();
        let result: Result.t = {
          name,
          iterations: opts.iterations,
          time: endTime -. startTime,
          minorWords: int_of_float(afterState.minor_words) - int_of_float(beforeState.minor_words),
          promotedWords: int_of_float(afterState.promoted_words) - int_of_float(beforeState.promoted_words),
          majorWords: int_of_float(afterState.major_words) - int_of_float(beforeState.major_words),
          minorCollections:
            afterState.minor_collections - beforeState.minor_collections,
          majorCollections: afterState.major_collections - beforeState.major_collections,
        };

        result;
      };

      iter();
    };

    let benchmark: Benchmark.t = {name, f: newCase};

    _benchmarks := List.append([benchmark], _benchmarks^);
  };

  let cli = () => {
    /* print_endline (<Pastel color=Red inverse=true>{"hello"}</Pastel>); */
    /* print_endline ("Cases: " ++ string_of_int(List.length(_benchmarks^))); */

    let benchmarks = List.rev(_benchmarks^);
    let results = List.map((t: Benchmark.t) => t.f(), benchmarks);

    Reporter.print(results);
    ();
  };
};
