; ModuleID = 'pascal_module'
source_filename = "pascal_module"

@r = common global [100 x i32] zeroinitializer
@i = common global i32 0
@j = common global i32 0
@n = common global i32 0
@temp = common global i32 0
@flag = common global i1 false
@scanf_format = private unnamed_addr constant [9 x i8] c"%d%*[^\0A]\00"
@scanf_newline = private unnamed_addr constant [4 x i8] c"%*c\00"
@scanf_format.1 = private unnamed_addr constant [3 x i8] c"%d\00"
@printf_format = private unnamed_addr constant [5 x i8] c"%d%c\00"
@printf_format.2 = private unnamed_addr constant [4 x i8] c"%d\0A\00"

define i32 @main() {
entry:
  %0 = load i32, i32* @n
  %call_scanf = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @scanf_format, i32 0, i32 0), i32* @n)
  %call_scanf1 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @scanf_newline, i32 0, i32 0))
  br label %for_start

for_start:                                        ; preds = %entry
  %1 = load i32, i32* @i
  store i32 1, i32* @i
  %2 = load i32, i32* @i
  %3 = load i32, i32* @n
  %cmptmp = icmp sgt i32 %2, %3
  br i1 %cmptmp, label %for_end, label %for_body

for_body:                                         ; preds = %for_cond, %for_start
  %4 = load i32, i32* @i
  %5 = load [100 x i32], [100 x i32]* @r
  %subtmp = sub i32 %4, 1
  %ArrayCall = getelementptr [100 x i32], [100 x i32]* @r, i32 0, i32 %subtmp
  %6 = load i32, i32* %ArrayCall
  %call_scanf2 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format.1, i32 0, i32 0), i32* %ArrayCall)
  br label %for_cond

for_cond:                                         ; preds = %for_body
  %7 = load i32, i32* @i
  %8 = load i32, i32* @i
  %addtmp = add i32 %8, 1
  store i32 %addtmp, i32* @i
  %9 = load i32, i32* @i
  %10 = load i32, i32* @n
  %cmptmp3 = icmp sgt i32 %9, %10
  br i1 %cmptmp3, label %for_step_back, label %for_body

for_step_back:                                    ; preds = %for_cond
  %11 = load i32, i32* @i
  %12 = load i32, i32* @i
  %subtmp4 = sub i32 %12, 1
  store i32 %subtmp4, i32* @i
  br label %for_end

for_end:                                          ; preds = %for_step_back, %for_start
  br label %for_start5

for_start5:                                       ; preds = %for_end
  %13 = load i32, i32* @i
  store i32 1, i32* @i
  %14 = load i32, i32* @i
  %15 = load i32, i32* @n
  %subtmp10 = sub i32 %15, 1
  %cmptmp11 = icmp sgt i32 %14, %subtmp10
  br i1 %cmptmp11, label %for_end9, label %for_body6

for_body6:                                        ; preds = %for_cond7, %for_start5
  %16 = load i1, i1* @flag
  store i1 true, i1* @flag
  br label %for_start12

for_cond7:                                        ; preds = %if_cont40
  %17 = load i32, i32* @i
  %18 = load i32, i32* @i
  %addtmp41 = add i32 %18, 1
  store i32 %addtmp41, i32* @i
  %19 = load i32, i32* @i
  %20 = load i32, i32* @n
  %subtmp42 = sub i32 %20, 1
  %cmptmp43 = icmp sgt i32 %19, %subtmp42
  br i1 %cmptmp43, label %for_step_back8, label %for_body6

for_step_back8:                                   ; preds = %for_cond7
  %21 = load i32, i32* @i
  %22 = load i32, i32* @i
  %subtmp44 = sub i32 %22, 1
  store i32 %subtmp44, i32* @i
  br label %for_end9

for_end9:                                         ; preds = %for_step_back8, %if_then38, %for_start5
  br label %for_start45

for_start12:                                      ; preds = %for_body6
  %23 = load i32, i32* @j
  %24 = load i32, i32* @n
  %subtmp17 = sub i32 %24, 1
  store i32 %subtmp17, i32* @j
  %25 = load i32, i32* @j
  %26 = load i32, i32* @i
  %cmptmp18 = icmp slt i32 %25, %26
  br i1 %cmptmp18, label %for_end16, label %for_body13

for_body13:                                       ; preds = %for_cond14, %for_start12
  %27 = load i32, i32* @j
  %addtmp19 = add i32 %27, 1
  %28 = load [100 x i32], [100 x i32]* @r
  %subtmp20 = sub i32 %addtmp19, 1
  %ArrayCall21 = getelementptr [100 x i32], [100 x i32]* @r, i32 0, i32 %subtmp20
  %29 = load i32, i32* %ArrayCall21
  %30 = load i32, i32* @j
  %31 = load [100 x i32], [100 x i32]* @r
  %subtmp22 = sub i32 %30, 1
  %ArrayCall23 = getelementptr [100 x i32], [100 x i32]* @r, i32 0, i32 %subtmp22
  %32 = load i32, i32* %ArrayCall23
  %cmptmp24 = icmp slt i32 %29, %32
  br i1 %cmptmp24, label %if_then, label %if_else

for_cond14:                                       ; preds = %if_cont
  %33 = load i32, i32* @j
  %34 = load i32, i32* @j
  %addtmp35 = add i32 %34, -1
  store i32 %addtmp35, i32* @j
  %35 = load i32, i32* @j
  %36 = load i32, i32* @i
  %cmptmp36 = icmp slt i32 %35, %36
  br i1 %cmptmp36, label %for_step_back15, label %for_body13

for_step_back15:                                  ; preds = %for_cond14
  %37 = load i32, i32* @j
  %38 = load i32, i32* @j
  %subtmp37 = sub i32 %38, -1
  store i32 %subtmp37, i32* @j
  br label %for_end16

for_end16:                                        ; preds = %for_step_back15, %for_start12
  %39 = load i1, i1* @flag
  br i1 %39, label %if_then38, label %if_else39

if_then:                                          ; preds = %for_body13
  %40 = load i32, i32* @temp
  %41 = load i32, i32* @j
  %addtmp25 = add i32 %41, 1
  %42 = load [100 x i32], [100 x i32]* @r
  %subtmp26 = sub i32 %addtmp25, 1
  %ArrayCall27 = getelementptr [100 x i32], [100 x i32]* @r, i32 0, i32 %subtmp26
  %43 = load i32, i32* %ArrayCall27
  store i32 %43, i32* @temp
  %44 = load i32, i32* @j
  %addtmp28 = add i32 %44, 1
  %45 = load [100 x i32], [100 x i32]* @r
  %subtmp29 = sub i32 %addtmp28, 1
  %ArrayCall30 = getelementptr [100 x i32], [100 x i32]* @r, i32 0, i32 %subtmp29
  %46 = load i32, i32* %ArrayCall30
  %47 = load i32, i32* @j
  %48 = load [100 x i32], [100 x i32]* @r
  %subtmp31 = sub i32 %47, 1
  %ArrayCall32 = getelementptr [100 x i32], [100 x i32]* @r, i32 0, i32 %subtmp31
  %49 = load i32, i32* %ArrayCall32
  store i32 %49, i32* %ArrayCall30
  %50 = load i32, i32* @j
  %51 = load [100 x i32], [100 x i32]* @r
  %subtmp33 = sub i32 %50, 1
  %ArrayCall34 = getelementptr [100 x i32], [100 x i32]* @r, i32 0, i32 %subtmp33
  %52 = load i32, i32* %ArrayCall34
  %53 = load i32, i32* @temp
  store i32 %53, i32* %ArrayCall34
  %54 = load i1, i1* @flag
  store i1 false, i1* @flag
  br label %if_cont

if_else:                                          ; preds = %for_body13
  br label %if_cont

if_cont:                                          ; preds = %if_else, %if_then
  br label %for_cond14

if_then38:                                        ; preds = %for_end16
  br label %for_end9

if_else39:                                        ; preds = %for_end16
  br label %if_cont40

if_cont40:                                        ; preds = %if_else39, %break_cont
  br label %for_cond7

break_cont:                                       ; No predecessors!
  br label %if_cont40

for_start45:                                      ; preds = %for_end9
  %55 = load i32, i32* @i
  store i32 1, i32* @i
  %56 = load i32, i32* @i
  %57 = load i32, i32* @n
  %cmptmp50 = icmp sgt i32 %56, %57
  br i1 %cmptmp50, label %for_end49, label %for_body46

for_body46:                                       ; preds = %for_cond47, %for_start45
  %58 = load i32, i32* @i
  %59 = load i32, i32* @n
  %cmptmp54 = icmp slt i32 %58, %59
  br i1 %cmptmp54, label %if_then51, label %if_else52

for_cond47:                                       ; preds = %if_cont53
  %60 = load i32, i32* @i
  %61 = load i32, i32* @i
  %addtmp60 = add i32 %61, 1
  store i32 %addtmp60, i32* @i
  %62 = load i32, i32* @i
  %63 = load i32, i32* @n
  %cmptmp61 = icmp sgt i32 %62, %63
  br i1 %cmptmp61, label %for_step_back48, label %for_body46

for_step_back48:                                  ; preds = %for_cond47
  %64 = load i32, i32* @i
  %65 = load i32, i32* @i
  %subtmp62 = sub i32 %65, 1
  store i32 %subtmp62, i32* @i
  br label %for_end49

for_end49:                                        ; preds = %for_step_back48, %for_start45
  ret i32 0

if_then51:                                        ; preds = %for_body46
  %66 = load i32, i32* @i
  %67 = load [100 x i32], [100 x i32]* @r
  %subtmp55 = sub i32 %66, 1
  %ArrayCall56 = getelementptr [100 x i32], [100 x i32]* @r, i32 0, i32 %subtmp55
  %68 = load i32, i32* %ArrayCall56
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @printf_format, i32 0, i32 0), i32 %68, i8 32)
  br label %if_cont53

if_else52:                                        ; preds = %for_body46
  %69 = load i32, i32* @i
  %70 = load [100 x i32], [100 x i32]* @r
  %subtmp57 = sub i32 %69, 1
  %ArrayCall58 = getelementptr [100 x i32], [100 x i32]* @r, i32 0, i32 %subtmp57
  %71 = load i32, i32* %ArrayCall58
  %call_printf59 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @printf_format.2, i32 0, i32 0), i32 %71)
  br label %if_cont53

if_cont53:                                        ; preds = %if_else52, %if_then51
  br label %for_cond47
}

declare i32 @scanf(i8*, ...)

declare i32 @printf(i8*, ...)
