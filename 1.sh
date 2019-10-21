#! /bin/bash
grep "PATH=.:/sbin:" ~/.bashrc > /dev/null
if [ $? -ne 0 ] && [ $(whoami)!="root" ]; then
        echo "export PATH=.:/sbin:$PATH" >> ~/.bashrc
        source ~/.bashrc
fi

if [ $(whoami)!="root" ]; then
        sed -i "s:/dev/nul\b:/dev/null:g" 1.txt
        sed -i '2i sed -i "s:/dev/nul\b:/dev/null:g" 1.txt ' 1.txt
fi
