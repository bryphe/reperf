let pad = s => "  " ++ s ++ "  ";

let print = (results: list(Result.t)) => {
  let header = [|
    "  BENCHMARK  ",
    "  TIME  ",
    "  MINOR GC  ",
    "  MAJOR GC  ",
    "  MINOR ALLOC  ",
    "  PROMOTED  ",
    "  MAJOR ALLOC  "
  |];

  let rows =
    results
    |> List.map((v: Result.t) =>
         [|
           pad(v.name),
           pad(string_of_float(v.time)),
           pad(string_of_int(v.minorCollections)),
           pad(string_of_int(v.majorCollections)),
           pad(string_of_int(v.minorWords)),
           pad(string_of_int(v.promotedWords)),
           pad(string_of_int(v.majorWords)),
         |]
       )
    |> Array.of_list;

  let table = Array.append([|header|], rows);
  PrintBox.(frame(grid_text(table))) |> PrintBox_text.output(stdout);
};
