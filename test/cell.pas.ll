; ModuleID = 'pascal_module'
source_filename = "pascal_module"

@a = common global [10000 x i32] zeroinitializer
@b = common global [10000 x i32] zeroinitializer
@m1 = common global i32 0
@m2 = common global i32 0
@n = common global i32 0
@i = common global i32 0
@p = common global i32 0
@t = common global i32 0
@s = common global i32 0
@f = common global i1 false
@printf_format = private unnamed_addr constant [6 x i8] c"%d%d\0A\00"

define i32 @main() {
entry:
  %0 = load i32, i32* @t
  store i32 0, i32* @t
  br label %for_start

for_start:                                        ; preds = %entry
  %1 = load i32, i32* @t
  store i32 1, i32* @t
  %2 = load i32, i32* @t
  %cmptmp = icmp sgt i32 %2, 150
  br i1 %cmptmp, label %for_end, label %for_body

for_body:                                         ; preds = %for_cond, %for_start
  %3 = load i32, i32* @s
  %4 = load i32, i32* @s
  %addtmp = add i32 %4, 1
  store i32 %addtmp, i32* @s
  br label %for_cond

for_cond:                                         ; preds = %for_body
  %5 = load i32, i32* @t
  %6 = load i32, i32* @t
  %addtmp1 = add i32 %6, 1
  store i32 %addtmp1, i32* @t
  %7 = load i32, i32* @t
  %cmptmp2 = icmp sgt i32 %7, 150
  br i1 %cmptmp2, label %for_step_back, label %for_body

for_step_back:                                    ; preds = %for_cond
  %8 = load i32, i32* @t
  %9 = load i32, i32* @t
  %subtmp = sub i32 %9, 1
  store i32 %subtmp, i32* @t
  br label %for_end

for_end:                                          ; preds = %for_step_back, %for_start
  %10 = load i32, i32* @t
  %11 = load i32, i32* @s
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @printf_format, i32 0, i32 0), i32 %10, i32 %11)
  ret i32 0
}

declare i32 @printf(i8*, ...)
