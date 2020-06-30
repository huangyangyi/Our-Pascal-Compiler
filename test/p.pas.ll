; ModuleID = 'pascal_module'
source_filename = "pascal_module"

@tcase = common global i32 0
@a = common global i32 0
@b = common global i32 0
@scanf_format = private unnamed_addr constant [3 x i8] c"%d\00"
@scanf_format.1 = private unnamed_addr constant [5 x i8] c"%d%d\00"
@printf_format = private unnamed_addr constant [4 x i8] c"%d\0A\00"

define i32 @main() {
entry:
  %0 = load i32, i32* @tcase
  %call_scanf = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format, i32 0, i32 0), i32* @tcase)
  br label %while_cond

while_cond:                                       ; preds = %while_body, %entry
  %1 = load i32, i32* @tcase
  %cmptmp = icmp sgt i32 %1, 0
  br i1 %cmptmp, label %while_body, label %while_end

while_body:                                       ; preds = %while_cond
  %2 = load i32, i32* @tcase
  %3 = load i32, i32* @tcase
  %subtmp = sub i32 %3, 1
  store i32 %subtmp, i32* @tcase
  %4 = load i32, i32* @a
  %5 = load i32, i32* @b
  %call_scanf1 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @scanf_format.1, i32 0, i32 0), i32* @a, i32* @b)
  %6 = load i32, i32* @a
  %7 = load i32, i32* @b
  %8 = call i32 @gcd(i32* @a, i32* @b)
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @printf_format, i32 0, i32 0), i32 %8)
  br label %while_cond

while_end:                                        ; preds = %while_cond
  ret i32 0
}

define i32 @gcd(i32*, i32*) {
entry:
  %2 = load i32, i32* %0
  %a = alloca i32
  store i32 %2, i32* %a
  %3 = load i32, i32* %1
  %b = alloca i32
  store i32 %3, i32* %b
  %gcd = alloca i32
  %4 = load i32, i32* %b
  %cmptmp = icmp eq i32 %4, 0
  br i1 %cmptmp, label %if_then, label %if_else

if_then:                                          ; preds = %entry
  %5 = load i32, i32* %gcd
  %6 = load i32, i32* %a
  store i32 %6, i32* %gcd
  br label %if_cont

if_else:                                          ; preds = %entry
  %7 = load i32, i32* %gcd
  %8 = load i32, i32* %b
  %9 = load i32, i32* %a
  %10 = load i32, i32* %b
  %modtmp = srem i32 %9, %10
  %"0_1" = alloca i32
  store i32 %modtmp, i32* %"0_1"
  %11 = call i32 @gcd(i32* %b, i32* %"0_1")
  store i32 %11, i32* %gcd
  br label %if_cont

if_cont:                                          ; preds = %if_else, %if_then
  %12 = load i32, i32* %gcd
  ret i32 %12
}

declare i32 @scanf(i8*, ...)

declare i32 @printf(i8*, ...)
