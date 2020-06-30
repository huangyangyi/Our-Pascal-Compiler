; ModuleID = 'pascal_module'
source_filename = "pascal_module"

@a = common global double 0.000000e+00
@s = common global double 0.000000e+00
@max = common global double 0.000000e+00
@min = common global double 0.000000e+00
@avg = common global double 0.000000e+00
@i = common global i32 0
@0 = private unnamed_addr constant [14 x i8] c"please input:\00"
@printf_format = private unnamed_addr constant [3 x i8] c"%s\00"
@scanf_format = private unnamed_addr constant [4 x i8] c"%lf\00"
@printf_format.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@printf_format.2 = private unnamed_addr constant [5 x i8] c"%lf\0A\00"
@scanf_format.3 = private unnamed_addr constant [4 x i8] c"%lf\00"
@printf_format.4 = private unnamed_addr constant [5 x i8] c"%lf\0A\00"

define i32 @main() {
entry:
  br label %label_

label_:                                           ; preds = %entry
  %0 = load [14 x i8], [14 x i8]* @0
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @printf_format, i32 0, i32 0), [14 x i8]* @0)
  br label %label_1

label_1:                                          ; preds = %label_
  %1 = load double, double* @a
  %call_scanf = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @scanf_format, i32 0, i32 0), double* @a)
  br label %label_2

label_2:                                          ; preds = %label_1
  %2 = load double, double* @s
  %3 = load double, double* @a
  store double %3, double* @s
  br label %label_3

label_3:                                          ; preds = %label_2
  %4 = load double, double* @max
  %5 = load double, double* @a
  store double %5, double* @max
  br label %label_4

label_4:                                          ; preds = %label_3
  %6 = load double, double* @min
  %7 = load double, double* @a
  store double %7, double* @min
  br label %label_5

label_5:                                          ; preds = %label_4
  br label %for_start

for_start:                                        ; preds = %label_5
  %8 = load i32, i32* @i
  store i32 2, i32* @i
  br label %for_body

for_body:                                         ; preds = %for_cond, %for_start
  br label %label_6

for_cond:                                         ; preds = %if_cont
  %9 = load i32, i32* @i
  %10 = load i32, i32* @i
  %addtmp = add i32 %10, 1
  store i32 %addtmp, i32* @i
  %11 = load i32, i32* @i
  %cmptmp = icmp sgt i32 %11, 5
  br i1 %cmptmp, label %for_end, label %for_body

for_end:                                          ; preds = %for_cond
  br label %label_22

label_6:                                          ; preds = %for_body
  br label %label_7

label_7:                                          ; preds = %label_6
  %12 = load i32, i32* @i
  %call_printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @printf_format.1, i32 0, i32 0), i32 %12)
  br label %label_9

label_9:                                          ; preds = %label_7
  %13 = load double, double* @a
  %call_printf10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @printf_format.2, i32 0, i32 0), double %13)
  br label %label_11

label_11:                                         ; preds = %label_9
  %14 = load double, double* @a
  %call_scanf12 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @scanf_format.3, i32 0, i32 0), double* @a)
  br label %label_13

label_13:                                         ; preds = %label_11
  %15 = load double, double* @s
  %16 = load double, double* @s
  %17 = load double, double* @a
  %addftmp = fadd double %16, %17
  store double %addftmp, double* @s
  br label %label_14

label_14:                                         ; preds = %label_13
  %18 = load double, double* @a
  %19 = load double, double* @max
  %cmpftmp = fcmp ogt double %18, %19
  br i1 %cmpftmp, label %if_then, label %if_else

if_then:                                          ; preds = %label_14
  br label %label_15

if_else:                                          ; preds = %label_14
  br label %label_16

if_cont:                                          ; preds = %if_cont19, %label_15
  br label %for_cond

label_15:                                         ; preds = %if_then
  %20 = load double, double* @max
  %21 = load double, double* @a
  store double %21, double* @max
  br label %if_cont

label_16:                                         ; preds = %if_else
  %22 = load double, double* @a
  %23 = load double, double* @min
  %cmpftmp20 = fcmp olt double %22, %23
  br i1 %cmpftmp20, label %if_then17, label %if_else18

if_then17:                                        ; preds = %label_16
  br label %label_21

if_else18:                                        ; preds = %label_16
  br label %if_cont19

if_cont19:                                        ; preds = %if_else18, %label_21
  br label %if_cont

label_21:                                         ; preds = %if_then17
  %24 = load double, double* @min
  %25 = load double, double* @a
  store double %25, double* @min
  br label %if_cont19

label_22:                                         ; preds = %for_end
  %26 = load double, double* @s
  %27 = load i32, i32* @i
  %28 = uitofp i32 %27 to double
  %addftmp23 = fadd double %26, %28
  %call_printf24 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @printf_format.4, i32 0, i32 0), double %addftmp23)
  ret i32 0
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)
