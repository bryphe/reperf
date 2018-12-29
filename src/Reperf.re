
type measureFunction = unit => unit;

let _trackingEnabled = ref(false);

let _getTime = () => Unix.gettimeofday();

let _recordCounter = (name: string) => {
    /* TODO */
    ();
}

let _recordTimingMeasurement = (name: string, time: float) => {
    /* TODO */
    ();
}

let measure = (name: string, f: measureFunction) => {
    switch(_trackingEnabled^) {
    | false => f()
    | true => {
       let startTime = _getTime(); 
       f();
       let endTime = _getTime();
       _recordTimingMeasurement(name, endTime -. startTime);
    }
    }
};

let counter = (name: string) => {
    switch(_trackingEnabled^) {
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
        let beforeStat = Gc.quick_stat();

        let startTime = _getTime();
        f();
        let endTime = _getTime();

        let afterState = Gc.quick_stat();

        ();
        
        /* let stats: { */
        /*     minorWords: minor_words - previousMinorWords, */
        /*     promotedWords: promoted_words - previousPromotedWords, */
        /*     majorWords: major_words - previousMajorWords, */
        /*     minorCollections: minor_collections - previousMinorCollections, */
        /*     majorCollections: major_collections - previousMajorCollections, */
        /* }; */
        /* stats; */
    };

    let startTime = _getTime();
    let count = ref(0);
    while (count^ < opts.iterations) {
        let _ = iter();
        count := count^ + 1;
    }

    let endTime = _getTime();
    let totalTime = endTime -. startTime;
}
