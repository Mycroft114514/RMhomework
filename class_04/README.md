运行命令：
cmake -S . -B build
cmake --build build
./build/class_04

除了写.gitignore和c_cpp_properties.json外未使用AI
选做题只完成了选做题1

基础题1
将共享roi“lena_roi_shared”,"lena_copy_shared"和克隆roi"lena_roi_clone","lena_copy_clone"进行对比，共享会修改原图副本，clone 不会修改原图副本。

基础题2
未做面积筛选时，背景块或小噪点也可能被统计为硬币

选做题1
调参工具代码在注释部分
自行调参的结果：H=37～71，S=40～255,V=33～255
fruits_tuned.png只改了HSV的mask范围，未进行开操作。