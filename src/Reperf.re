module Config = Config;

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

  type testFunction = unit => unit;

  let bench =
      (~name: string, ~f: testFunction, ~options=Config.config.options, ()) => {
    let newCase = () => {
      let opts = options;
      let iter = () => {
        /* Garbage collect to clear out env */
        Gc.full_major();
        let beforeState = Gc.quick_stat();

        let startTime = _getTime();
        let count = ref(0);
        while (count^ < opts.iterations) {
          f();
          count := count^ + 1;
        };
        let endTime = _getTime();

        let afterState = Gc.quick_stat();
        let result: Result.t = {
          name,
          time: endTime -. startTime,
          minorWords: 0,
          promotedWords: 0,
          majorWords: 0,
          minorCollections:
            afterState.minor_collections - beforeState.minor_collections,
          majorCollections: 0,
        };

        /* let result: Result.t = { */
        /*     minorWords: minor_words - previousMinorWords, */
        /*     promotedWords: promoted_words - previousPromotedWords, */
        /*     majorWords: major_words - previousMajorWords, */
        /*     minorCollections: minor_collections - previousMinorCollections, */
        /*     majorCollections: major_collections - previousMajorCollections, */
        /* }; */
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
