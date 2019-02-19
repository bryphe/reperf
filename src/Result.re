type t = {
  name: string,
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
      ~time,
      ~minorWords,
      ~promotedWords,
      ~majorWords,
      ~minorCollections,
      ~majorCollections,
    ) => {
  name,
  time,
  minorWords,
  promotedWords,
  majorWords,
  minorCollections,
  majorCollections,
};
