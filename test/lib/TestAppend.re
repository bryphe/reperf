open TestFramework;

let arrayAppend = () => {
    let _ = Array.append([|"a"|], [|"b"|]);
};

let listAppend = () => {
    let _ = List.append(["a"], ["b"]);
};

bench(
    ~name="Append: Array",
    ~f=arrayAppend,
    ());

bench(
    ~name="Append: List",
    ~f=listAppend,
    (),
);
