import sys

resourceFile = open(sys.argv[1], "rb")
resource = resourceFile.read()
resourceFile.close()

resourceName = ""
for character in sys.argv[1]:
    if character == "/" or character == "\\" or character == "-" or character == ":" or character == ".":
        resourceName += "_"
    else:
        resourceName += character

headerGuard = "INCLUDED_RESOURCE_" + resourceName.capitalize()

resourceLength = len(resource)

outputHeader = f"""#ifndef {headerGuard}
#define {headerGuard}
#pragma once
namespace resources{{extern const unsigned char {resourceName}[{resourceLength}];}}
#endif
"""

outputHeaderFile = open(sys.argv[2], "w")
outputHeaderFile.write(outputHeader)
outputHeaderFile.close()

resourceArray = ""
i = 1
for byte in resource:
    if i == len(resource):
        resourceArray = resourceArray + f"{byte}"
    else:
        resourceArray = resourceArray + f"{byte},"
    i = i + 1

outputSource = f"""namespace resources
{{
    const unsigned char {resourceName}[{resourceLength}] = {{{resourceArray}}};
}}
"""

outputSourceFile = open(sys.argv[3], "w")
outputSourceFile.write(outputSource)
outputSourceFile.close()