import os
import shutil
import sys

if len(sys.argv) < 3:
    print("usage: alias <target> <alias>")
    sys.exit()


target = sys.argv[1]
alias = sys.argv[2]

if target == "":
    print("target can't be empty")
    sys.exit()

if alias == "":
    print("target can't be empty")
    sys.exit()

templ = f"""{{bitmap
    {{frame "{target}_00.tga"}}
    {{frame "{target}_01.tga"}}
    {{frame "{target}_02.tga"}}
    {{frame "{target}_03.tga"}}
}}"""

filename = f"{alias}.ebm"

os.chdir("./interface/scene")
for fl in ("unit_icon", "unit_icon_small"):
    with open(os.path.join(fl, filename), "w+") as f:
        f.write(templ)
        
    print(f"written {f.name}!")