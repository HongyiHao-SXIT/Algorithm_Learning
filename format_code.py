import os
import re

# 修改为你要整理的代码根目录
ROOT_DIR = r"./Operating_System"
INDENT_SIZE = 4

def format_cpp(text: str) -> str:
    lines = text.splitlines()
    result = []
    indent = 0
    add_blank = False

    for raw in lines:
        line = raw.rstrip()

        # 保留空行（但去除多余缩进）
        if not line.strip():
            if not add_blank:   # 避免连续空行
                result.append("")
                add_blank = True
            continue
        add_blank = False

        # 去掉行首多余空格
        stripped = line.lstrip()

        # 处理右花括号
        if stripped.startswith('}'):
            indent = max(0, indent - 1)

        # 缩进
        prefix = " " * (INDENT_SIZE * indent)
        formatted = prefix + stripped

        result.append(formatted)

        # 如果本行以 { 结束且不是单独的 { ，缩进+1
        if re.search(r"\{\s*$", stripped):
            indent += 1

    # 统一文件末尾换行
    return "\n".join(result).rstrip() + "\n"


def process_file(path: str):
    with open(path, "r", encoding="utf-8", errors="ignore") as f:
        old = f.read()
    new = format_cpp(old)
    if old != new:
        with open(path, "w", encoding="utf-8") as f:
            f.write(new)
        print(f"Formatted: {path}")


def main():
    for dirpath, _, files in os.walk(ROOT_DIR):
        for f in files:
            if f.endswith((".c", ".cpp", ".h", ".hpp")):
                process_file(os.path.join(dirpath, f))


if __name__ == "__main__":
    main()
    print("✅ 全部文件格式化完成！")
