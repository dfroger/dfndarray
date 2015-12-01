# TODO: debug version -O0 -g -DDFNDARRAY_RUNTIME_CHECK

if [ "$(uname)" == "Darwin" ]
then
    export MACOSX_DEPLOYMENT_TARGET=10.7

    export CC=clang
    export CXX=clang++

    unset CXXFLAGS
    unset CFLAGS
    unset LDFLAGS

    cd dfndarray
    $PYTHON ../waf configure \
        --prefix=$PREFIX \
        --python-bindings \
        --cflags='-O3 -DNDEBUG -mmacosx-version-min=10.7 -arch x86_64' \
        --cxxflags='-O3 -DNDEBUG -stdlib=libc++ -mmacosx-version-min=10.7 -arch x86_64' \
        --ldflags="-L$PREFIX/lib -O3 -DNDEBUG -stdlib=libc++ -mmacosx-version-min=10.7 -arch x86_64" \
        --remove-isysroot
else
    cd dfndarray
    $PYTHON ../waf configure \
        --prefix=$PREFIX \
        --python-bindings \
        --cflags='-O3 -DNDEBUG' \
        --cxxflags='-O3 -DNDEBUG' \
        --ldflags='-O3 -DNDEBUG'
fi

$PYTHON ../waf build -v
$PYTHON ../waf install

