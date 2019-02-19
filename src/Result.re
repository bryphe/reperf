type t = {
    time: float,
    minorWords: int,
    promotedWords: int,
    majorWords: int,
    minorCollections: int,
    majorCollections: int,
    /* TODO: Counters */
    /* TODO: Timings */
};

let create = (
   ~time,
    ~minorWords,
    ~promotedWords,
    ~majorWords,
    ~minorCollections,
    ~majorCollections
) => {
   time,
   minorWords,
   promotedWords,
   majorWords,
   minorCollections,
   majorCollections,
}
