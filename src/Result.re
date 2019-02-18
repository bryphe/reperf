type t = {
    minorWords: int,
    promotedWords: int,
    majorWords: int,
    minorCollections: int,
    majorCollections: int,
    /* TODO: Counters */
    /* TODO: Timings */
};

let create = (
    ~minorWords,
    ~promotedWords,
    ~majorWords,
    ~minorCollections,
    ~majorCollections
) => {
   minorWords,
   promotedWords,
   majorWords,
   minorCollections,
   majorCollections,
}
