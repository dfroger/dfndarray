cd dfndarray
$PYTHON ../waf configure --prefix=$PREFIX --python-bindings
$PYTHON ../waf build
$PYTHON ../waf install
