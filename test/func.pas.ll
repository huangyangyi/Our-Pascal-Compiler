; ModuleID = 'pascal_module'
source_filename = "pascal_module"

@a = common global i32 0
@b = common global i32 0
@printf_format = private unnamed_addr constant [8 x i8] c"%d%c%d\0A\00"
@printf_format.1 = private unnamed_addr constant [8 x i8] c"%d%c%d\0A\00"
@printf_format.2 = private unnamed_addr constant [8 x i8] c"%d%c%d\0A\00"
@printf_format.3 = private unnamed_addr constant [8 x i8] c"%d%c%d\0A\00"

define i32 @main() {
entry:
  %0 = load i32, i32* @a
  store i32 3, i32* @a
  %1 = load i32, i32* @b
  store i32 4, i32* @b
  %2 = load i32, i32* @a
  %3 = load i32, i32* @b
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @printf_format.2, i32 0, i32 0), i32 %2, i8 32, i32 %3)
  %4 = load i32, i32* @a
  %5 = load i32, i32* @b
  call void @f(i32* @a, i32* @b)
  %6 = load i32, i32* @a
  %7 = load i32, i32* @b
  %call_printf1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @printf_format.3, i32 0, i32 0), i32 %6, i8 32, i32 %7)
  ret i32 0
}

define void @f(i32*, i32*) {
entry:
  %2 = load i32, i32* %0
  %a = alloca i32
  store i32 %2, i32* %a
  %3 = load i32, i32* %a
  %4 = load i32, i32* %1
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @printf_format, i32 0, i32 0), i32 %3, i8 32, i32 %4)
  call void @g(i32* %a, i32* %1)
  %5 = load i32, i32* %1
  store i32 5, i32* %1
  %6 = load i32, i32* %a
  %7 = load i32, i32* %1
  %call_printf1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @printf_format.1, i32 0, i32 0), i32 %6, i8 32, i32 %7)
  ret void
}

define void @g(i32*, i32*) {
entry:
  %2 = load i32, i32* %0
  store i32 2, i32* %0
  ret void
}

declare i32 @printf(i8*, ...)
