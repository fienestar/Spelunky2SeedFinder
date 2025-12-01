add_executable(Spelunky2SeedFinderInjector "")

target_precompile_headers(Spelunky2SeedFinderInjector PRIVATE <chrono>)
target_precompile_headers(Spelunky2SeedFinderInjector PRIVATE <thread>)

target_include_directories(Spelunky2SeedFinderInjector PRIVATE ../3rdParty/overlunky/src/injector/)
target_include_directories(Spelunky2SeedFinderInjector PRIVATE ../3rdParty/overlunky/src/shared/)
target_include_directories(Spelunky2SeedFinderInjector PRIVATE ../3rdParty/overlunky/src/fmt/include/)

target_link_libraries(Spelunky2SeedFinderInjector fmt)

add_subdirectory(src)

set_target_properties(Spelunky2SeedFinderInjector PROPERTIES OUTPUT_NAME Spelunky2SeedFinder)
