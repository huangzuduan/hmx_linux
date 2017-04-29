#/usr/bin

echo "开始生成"

protoc  itemslots.proto --cpp_out=.
protoc  character.proto --cpp_out=.
protoc  sorlists.proto --cpp_out=.
protoc  chatmsg.proto --cpp_out=.

echo "生成文件完成"
