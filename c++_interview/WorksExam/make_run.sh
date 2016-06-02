

# 变量与等号之间不能存在空格 ， 这个变量是 保存 pwd 命令执行之后的结果
cur_path=`pwd`

# shell 中字符串的连接，就是直接写在一起就好了
if [ -f $cur_path/"xhj" ]
then
  rm ./xhj
fi

g++ $1 -o xhj
./xhj
rm ./xhj
