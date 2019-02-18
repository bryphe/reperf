/*
 * Options.re
 *
 * Configuration for a Reperf session
 */

type t = {
    iterations: int,
};

let create = (~iterations, ()) => {
    iterations
};
