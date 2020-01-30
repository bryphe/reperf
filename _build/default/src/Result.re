type t = {
  name: string,

  /* Number of times the test was run */
  iterations: int,
  time: float,
  minorWords: int,
  promotedWords: int,
  majorWords: int,
  minorCollections: int,
  majorCollections: int,
  /* TODO: Counters */
  /* TODO: Timings */
};

let create =
    (
      ~name,
      ~iterations,
      ~time,
      ~minorWords,
      ~promotedWords,
      ~majorWords,
      ~minorCollections,
      ~majorCollections,
    ) => {
  name,
  iterations,
  time,
  minorWords,
  promotedWords,
  majorWords,
  minorCollections,
  majorCollections,
};
