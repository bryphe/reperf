/*
 * Options.re
 */

type t = {
    iterations: int,
};

let create = (~iterations=100, ()) => {
    let ret: t = { 
        iterations: iterations,
    };
    ret;
};
