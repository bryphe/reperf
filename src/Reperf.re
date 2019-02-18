
module type Args = {
    let config: Config.t;
}

module Make = (Config: Args) => {

    let _getTime = Unix.gettimeofday;

    type testFunction = unit => unit;

    let benchmark = (~name: string, ~f: testFunction, ~options=Config.config.options, ()) => {

        let opts = options;
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
            
    };
    

    let cli = () => {
     ();
    };
}
