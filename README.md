# reperf

### Native Reason + JSOO Cross-Platform Performance Benchmarking Tools

## Why?

A key value proposition of native [Reason](https://reasonml.github.io) is building _fast_, _native_ apps.

However, apps and tools can often start out fast when they are simple - but decay as more features and complexity are added.

`reperf` is inspired by the [core_bench](https://github.com/janestreet/core_bench) tools from Janestreet. Unfortunately, at least at time of writing, the `core_bench` OPAM package does not work on Windows.

## Features

`reperf` helps with the following:
- __Timing__ - how much time am I spending in a code block?
- __Call count__ - how often is this code-path being called?
- __Allocations__ - how is a code-block impacting the garbage collector?

In addition, `reperf` supports _benchmarks_, which are test cases that exercise performance scenarios. `reperf` can output a JSON performance report, and compare it with previous iterations - and fail if a regression is detected. This helps you keep your app fast!

## Usage

## License

[MIT License](LICENSE)
