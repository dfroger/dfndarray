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
        --cflags='-mmacosx-version-min=10.7 -arch x86_64' \
        --cxxflags='-stdlib=libc++ -mmacosx-version-min=10.7 -arch x86_64' \
        --ldflags='-stdlib=libc++ -mmacosx-version-min=10.7 -arch x86_64' \
        --remove-isysroot
else
    cd dfndarray
    $PYTHON ../waf configure \
        --prefix=$PREFIX \
        --python-bindings
fi

$PYTHON ../waf build -v
$PYTHON ../waf install

