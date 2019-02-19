open TestFramework;

let floatMultiply = () => {
    let _ = 2. *. 2.;
};

let intMultiply = () => {
   let _ = 2 * 2;
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
