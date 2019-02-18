/*
 * Config.re
 *
 * Configuration for a Reperf session
 */

type t = {
    snapshotDir: string,
    options: Options.t,
};

let create = (
    ~snapshotDir,
    ~options=Options.create(),
    (),
) => {
    snapshotDir,
};
