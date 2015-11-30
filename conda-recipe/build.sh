export MACOSX_DEPLOYMENT_TARGET=10.7
export CC=clang
export CXX=clang++

unset CXXFLAGS
unset CFLAGS
unset LDFLAGS

cd dfndarray
waf configure --prefix=$PREFIX --python-bindings
waf build
waf install
