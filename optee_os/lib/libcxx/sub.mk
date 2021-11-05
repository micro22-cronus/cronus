
global-incdirs-y += build/include

$(eval $(call bash -c "mkdir build-libcxx"))

srcs-y += __dso_handle.cpp

# link-ldflags-y += -Wl,--whole-archive lib/libc++.a
libfiles += lib/libcxx/build/lib/libc++.a
libfiles += lib/libcxx/build-abi/lib/libc++abi.a
libfiles += lib/libcxx/build-unwind/lib/libunwind.a
