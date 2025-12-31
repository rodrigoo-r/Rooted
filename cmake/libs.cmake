# ============================================================================ #
# Libraries
# ============================================================================ #

include(FetchContent)

FetchContent_Declare(
        Celery
        GIT_REPOSITORY https://github.com/rodrigoo-r/Celery.git
        GIT_TAG        master
)
FetchContent_MakeAvailable(Celery)

target_link_libraries(Rooted PRIVATE Celery::Celery)