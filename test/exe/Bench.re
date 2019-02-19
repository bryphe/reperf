
ReperfSampleTests.TestFramework.cli();


let b2 =
  PrintBox.(
    frame(
        grid_text([|[|"  BENCHMARK  ", "  TIME  ", "  MINOR GC  ", "  MAJOR GC  "|], [|"test1", "100", "1000", "10000"|]|]),
    )
  );

PrintBox_text.output(stdout, b2);
