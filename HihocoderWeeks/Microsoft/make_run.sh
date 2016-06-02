
cur_path=$PWD

if [ -f $cur_path/"xhj" ]
then
  rm ./xhj
fi

g++ $1 -o xhj
./xhj
rm ./xhj
