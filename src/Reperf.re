
type measureFunction = unit => unit;

let _trackingEnabled = ref(false);

let _getTime = () => Unix.gettimeofday();

let _recordCounter = (name: string) => {
    /* TODO */
}

let _recordTimingMeasurement = (name: string, time: float) => {
    /* TODO */
}

let measure = (name: string, f: measureFunction) => {
    switch(_trackingEnabled) {
    | false => f()
    | true => {
       let startTime = _getTime(); 
       f();
       let endTime = _getTime();
       _recordTimingMeasurement(name, endTime - startTime);
    }
    }
};

let counter = (name: string) => {
    switch(_trackingEnabled) {
    | false => ()
    | true => _recordCounter(name);
    }
};

type benchmarkOptions = {
    iterations: int,
};

let defaultOptions: benchmarkOptions = {
    iterations: 1000,
};

type benchmarkIterationResult = {
    minorWords: int,
    promotedWords: int,
    majorWords: int,
    minorCollections: int,
    majorCollections: int,
    /* TODO: Counters */
    /* TODO: Timings */
};

let benchmark = (~opts=defaultOptions, name: string, f: measureFunction) => {
    
    let iter = () => {

        /* Garbage collect to clear out env */
        Gc.full_major();   
        let { minor_words, promoted_words, major_words, minor_collections, major_collections, } = Gc.quick_stat();

        let previousMinorWords = minor_words;
        let previousPromotedWords = promoted_words;
        let previousMajorWords = major_words;
        let previousMinorCollections = minor_collections;
        let previousMajorCollections = major_collections;

        let startTime = _getTime();
        f();
        let endTime = _getTime();

        let { minor_words, promoted_words, major_words, minor_collections, major_collections, } = Gc.quick_stat();
    };

    let count = ref(0);
    while (count < opts.iterations) {
        iter();
        count := count^ + 1;
    }
}
