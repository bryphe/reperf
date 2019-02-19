open TestFramework;

let floatMultiply = () => {
    /* print_endline("ab"); */
    let _ = Array.append([|"a"|], [|"b"|]);
};

let intMultiply = () => {
    let _ = List.append(["a"], ["b"]);
};

bench(
    ~name="float multiplication",
    ~f=floatMultiply,
    ());

bench(
    ~name="int multiplication",
    ~f=intMultiply,
    (),
);
