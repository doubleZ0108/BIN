On Error Resume Next
Set FSO = CreateObject("Scripting.FileSystemObject")
FSO.DeleteFile(FSO.GetSpecialFolder(0) & "\shelliconcache")
Set FSO = Nothing
Set Pros = GetObject("winmgmts:\\.\root\cimv2").ExecQuery ("Select * from Win32_Process Where Name = 'explorer.exe'")
For Each Pro in Pros
Pro.Terminate
Next