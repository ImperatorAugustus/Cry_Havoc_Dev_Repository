import os
import shutil
import re


for root, dirs, files in os.walk("./"):
    for name in files:
        if name.endswith(".lua"):
            lines = []
            with open(os.path.join(root, name)) as f:
                for line in f:
                    if "\"Doctrine\", " in line:
                        t = re.search("\"Doctrine\", ", line)
                            
                        # replace timer with adjusted value
                        line = re.sub("\"Doctrine\", ", f"", line)
                        
                        print("N:", line)
                        lines.append(line)
                    else:
                        lines.append(line)
                        continue
                    
                    
            with open(os.path.join(root, name), "w") as f:
                for line in lines:
                    f.write(line)