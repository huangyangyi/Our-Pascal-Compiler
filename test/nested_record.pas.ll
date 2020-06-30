; ModuleID = 'pascal_module'
source_filename = "pascal_module"

@a = common global { i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } } zeroinitializer
@scanf_format = private unnamed_addr constant [5 x i8] c"%d%d\00"

define i32 @main() {
entry:
  %0 = load { i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }, { i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }* @a
  %1 = load i32, i32* getelementptr inbounds ({ i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }, { i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }* @a, i32 0, i32 0)
  %2 = load { i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }, { i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }* @a
  %3 = load i32, i32* getelementptr inbounds ({ i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }, { i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }* @a, i32 0, i32 1)
  %call_scanf = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @scanf_format, i32 0, i32 0), i32* getelementptr inbounds ({ i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }, { i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }* @a, i32 0, i32 0), i32* getelementptr inbounds ({ i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }, { i32, i32, { i32, i32 }, { i32, i32 }, { i32, i32 } }* @a, i32 0, i32 1))
  ret i32 0
}

declare i32 @scanf(i8*, ...)
