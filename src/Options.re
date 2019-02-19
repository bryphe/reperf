/*
 * Options.re
 */

type t = {
    iterations: int,
};

let create = (~iterations=1000000, ()) => {
    let ret: t = { 
        iterations: iterations,
    };
    ret;
};
