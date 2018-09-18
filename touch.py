import sys
import os
import datetime

authorName = "Alan Zhang"
dateStr = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
hFileHeader = "/*\nDecription\t:\nAuthor\t\t:"+authorName+"\nDate\t\t:"+dateStr+"\nVersion\t\t:1.0.0\n*/\n"
hFileBody = "\n#ifdef __cplusplus\nextern "+"C"+ "{\n#endif\n\n\n\n\n#ifdef __cplusplus\n}\n#endif\n"

if len(sys.argv)<=1 or len(sys.argv)>=4 :
	print("no input error")
	os.exit(0)
else :
	if len(sys.argv)==2 :
		fileName = sys.argv[1]
		hFilePath = fileName+'.h'
		cFilePath = fileName+'.c'
	else :
		fileName = sys.argv[2]
		hFilePath = sys.argv[1]+"/"+fileName+'.h'
		cFilePath = sys.argv[1]+"/"+fileName+'.c'


fileNameUseToDefine = "_"+fileName.upper()+"_H_"
hFileDefineHeader = "#ifndef "+fileNameUseToDefine + "\n#define " + fileNameUseToDefine + "\n"
hFileDefineTil = "#endif\n"
cFileBody = "#include \""+fileName+".h\"\n\n\n";

if os.access(hFilePath,os.F_OK):
	print("head file exit,you want delete it Y/n:")
	deleteCmd = input() 

	if deleteCmd=="" or 'y' == deleteCmd[0] or 'Y' == deleteCmd[0] :
		os.remove(hFilePath)
		myFile = open(hFilePath,'w+')
		myFile.write(hFileHeader+hFileDefineHeader+hFileBody+hFileDefineTil)
		print("create file"+hFilePath+" succeed\n")
	else:
		print("create file"+hFilePath+" failed\n")
		os.exit(0)

else :
	myFile = open(hFilePath,'w+')
	myFile.write(hFileHeader+hFileDefineHeader+hFileBody+hFileDefineTil)
	print("create file"+hFilePath+" succeed\n")

if os.access(cFilePath,os.F_OK):
	print("c file exit,you want delete it Y/n:")
	deleteCmd = input() 

	if deleteCmd=="" or 'y' == deleteCmd[0] or 'Y' == deleteCmd[0] :
		os.remove(cFilePath)
		myFile = open(cFilePath,'w+')
		myFile.write(hFileHeader+cFileBody)
		print("create file"+cFilePath+" succeed\n")
	else:
		print("create file"+cFilePath+" failed\n")
		os.exit(0)

else :
	myFile = open(cFilePath,'w+')
	myFile.write(hFileHeader+cFileBody)
	print("create file"+cFilePath+" succeed\n")
