PROJECT_NAME='OpenGLMaxSat'
XML_PATH='EvalMaxSAT_HSTT/xml-files/USAWestside2009.xml'
cmake -S . -B build
make -C build
if [ $? -eq 0 ]; then
    ./build/${PROJECT_NAME} ${XML_PATH} 
else
    echo "**ERREUR : COMPILATION ARRÊTÉE**"
    exit 1
fi 
