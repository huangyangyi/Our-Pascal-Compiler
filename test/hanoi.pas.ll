; ModuleID = 'pascal_module'
source_filename = "pascal_module"

@N = common global i32 0
@printf_format = private unnamed_addr constant [3 x i8] c"%d\00"
@0 = private unnamed_addr constant [3 x i8] c"->\00"
@printf_format.1 = private unnamed_addr constant [3 x i8] c"%s\00"
@printf_format.2 = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@printf_format.3 = private unnamed_addr constant [3 x i8] c"%d\00"
@1 = private unnamed_addr constant [3 x i8] c"->\00"
@printf_format.4 = private unnamed_addr constant [3 x i8] c"%s\00"
@printf_format.5 = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@scanf_format = private unnamed_addr constant [3 x i8] c"%d\00"

define i32 @main() {
entry:
  br label %label_

label_:                                           ; preds = %entry
  %0 = load i32, i32* @N
  %call_scanf = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format, i32 0, i32 0), i32* @N)
  br label %label_1

label_1:                                          ; preds = %label_
  %1 = load i32, i32* @N
  %"0_3" = alloca i32
  store i32 1, i32* %"0_3"
  %"0_4" = alloca i32
  store i32 3, i32* %"0_4"
  %"0_5" = alloca i32
  store i32 2, i32* %"0_5"
  call void @move(i32* %"0_3", i32* %"0_4", i32* %"0_5", i32* @N)
  ret i32 0
}

define void @move(i32*, i32*, i32*, i32*) {
entry:
  %4 = load i32, i32* %0
  %a = alloca i32
  store i32 %4, i32* %a
  %5 = load i32, i32* %1
  %b = alloca i32
  store i32 %5, i32* %b
  %6 = load i32, i32* %2
  %c = alloca i32
  store i32 %6, i32* %c
  %7 = load i32, i32* %3
  %N = alloca i32
  store i32 %7, i32* %N
  br label %label_

label_:                                           ; preds = %entry
  %8 = load i32, i32* %N
  %cmptmp = icmp eq i32 %8, 1
  br i1 %cmptmp, label %if_then, label %if_else

if_then:                                          ; preds = %label_
  br label %label_1

if_else:                                          ; preds = %label_
  br label %label_7

if_cont:                                          ; preds = %label_15, %label_5
  ret void

label_1:                                          ; preds = %if_then
  br label %label_2

label_2:                                          ; preds = %label_1
  %9 = load i32, i32* %a
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @printf_format, i32 0, i32 0), i32 %9)
  br label %label_3

label_3:                                          ; preds = %label_2
  %10 = load [3 x i8], [3 x i8]* @0
  %call_printf4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @printf_format.1, i32 0, i32 0), [3 x i8]* @0)
  br label %label_5

label_5:                                          ; preds = %label_3
  %11 = load i32, i32* %b
  %call_printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @printf_format.2, i32 0, i32 0), i32 %11)
  br label %if_cont

label_7:                                          ; preds = %if_else
  br label %label_8

label_8:                                          ; preds = %label_7
  %12 = load i32, i32* %a
  %13 = load i32, i32* %c
  %14 = load i32, i32* %b
  %15 = load i32, i32* %N
  %subtmp = sub i32 %15, 1
  %"0_1" = alloca i32
  store i32 %subtmp, i32* %"0_1"
  call void @move(i32* %a, i32* %c, i32* %b, i32* %"0_1")
  br label %label_9

label_9:                                          ; preds = %label_8
  %16 = load i32, i32* %a
  %call_printf10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @printf_format.3, i32 0, i32 0), i32 %16)
  br label %label_11

label_11:                                         ; preds = %label_9
  %17 = load [3 x i8], [3 x i8]* @1
  %call_printf12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @printf_format.4, i32 0, i32 0), [3 x i8]* @1)
  br label %label_13

label_13:                                         ; preds = %label_11
  %18 = load i32, i32* %b
  %call_printf14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @printf_format.5, i32 0, i32 0), i32 %18)
  br label %label_15

label_15:                                         ; preds = %label_13
  %19 = load i32, i32* %c
  %20 = load i32, i32* %b
  %21 = load i32, i32* %a
  %22 = load i32, i32* %N
  %subtmp16 = sub i32 %22, 1
  %"0_2" = alloca i32
  store i32 %subtmp16, i32* %"0_2"
  call void @move(i32* %c, i32* %b, i32* %a, i32* %"0_2")
  br label %if_cont
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)
