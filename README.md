<h1 align="center">RailShell</h1>
<div align="center">
    <img alt="Travis (.com)" src="https://img.shields.io/travis/com/RailRunner166/RailShell.svg?logo=travis&style=flat-square">
    <img alt="GitHub release" src="https://img.shields.io/github/release/RailRunner166/RailShell.svg?style=flat-square">
</div>

## Development
Developing the app isnt easy, here is some stuff you should read first.

### Building
Building the application is as simple as running:
```sh
$ chmod +x scripts/build.sh
$ ./scripts/build.sh
```

### Code Style
It is important that you adhere to our code style.

#### Clang Format
Only format the items in the `includes` and `src` directories. We use two-space tabs, so set your editor accordingly.

We have a [Clang Format config file](.clang-format) that defines our style preferences.

Our preferred way of running `clang-format` is as so:
```sh
$ clang-format -i src/* includes/*
```
