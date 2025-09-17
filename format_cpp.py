import subprocess
from pathlib import Path

# 要格式化的扩展名
EXTS = {".c", ".cpp", ".cc", ".h", ".hpp"}

# clang-format 风格，可以改为 "Google", "LLVM", "Mozilla", "WebKit", "Microsoft" 等
STYLE = "Google"  # 或 "LLVM"

def format_file(file_path: Path):
    """调用 clang-format 格式化单个文件"""
    try:
        subprocess.run(
            ["clang-format", "-i", f"--style={STYLE}", str(file_path)],
            check=True
        )
        print(f"[OK] Formatted: {file_path}")
    except subprocess.CalledProcessError as e:
        print(f"[FAIL] {file_path}: {e}")
    except FileNotFoundError:
        print("❌ 未找到 clang-format，请先安装！")
        exit(1)

def main():
    root = Path(".").resolve()
    print(f"📂 正在整理目录: {root}")
    for path in root.rglob("*"):
        if path.suffix.lower() in EXTS:
            format_file(path)

if __name__ == "__main__":
    main()
