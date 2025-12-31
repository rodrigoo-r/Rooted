<div align="center">
    <img src="https://assets.zelixlang.dev/logo.png?update=true" height="60" width="60">
    <h1>The Zelix Programming Language</h1>
    A safe, high-performance systems language.
    <br>
    <br>

[![GitHub](https://img.shields.io/github/license/zelix-lang/Zelix)](LICENSE)
![GitHub repo size](https://img.shields.io/github/repo-size/zelix-lang/Zelix)
![GitHub Issues or Pull Requests](https://img.shields.io/github/issues/zelix-lang/Zelix)
![GitHub Repo stars](https://img.shields.io/github/stars/zelix-lang/Zelix?style=flat)

[Website][Website] | [Documentation][Documentation] | [Contributing][Contributing]
</div>

---

[Website]: https://zelixlang.dev
[Documentation]: https://docs.zelixlang.dev
[Contributing]: CONTRIBUTING.md
[stdlib]: https://github.com/zelix-lang/stdlib

Welcome to the repository of the `Rooted` library, a subproject
of the **Zelix Programming Language**.

Rooted provides an easy-to-use interface for printing tree-like
data structures in a visually appealing manner.

### 📦 Installation

To include `Rooted` in your Zelix project, you have to use 
CMake's `FetchContent` module. Add the following to your
`CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    Rooted
    GIT_REPOSITORY https://github.com/zelix-lang/rooted.git
    GIT_TAG master
)

FetchContent_MakeAvailable(Rooted)

target_link_libraries(your_target PRIVATE Rooted)
```

---

### 🤝 Getting Involved
We welcome contributions! Whether you're fixing bugs, adding features, or improving documentation, your help is
appreciated. Check out our [Contributing Guide][Contributing] for more details.

---

### 📝 License
Zelix is licensed under the [Apache License 2.0](LICENSE).