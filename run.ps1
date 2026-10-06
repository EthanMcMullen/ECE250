param(
    [Parameter(Position = 0)]
    [string]$Source = "problems/example.cpp"
)

$ErrorActionPreference = "Stop"
$repoRoot = $PSScriptRoot
$sourcePath = Join-Path $repoRoot $Source

if (-not (Test-Path -LiteralPath $sourcePath -PathType Leaf)) {
    throw "Source file not found: $sourcePath"
}

$compiler = Get-Command "g++" -ErrorAction SilentlyContinue
if (-not $compiler) {
    throw "g++ was not found on PATH. Install a C++ compiler, then try again."
}

$buildDirectory = Join-Path $repoRoot "build"
New-Item -ItemType Directory -Force -Path $buildDirectory | Out-Null

$executableName = [System.IO.Path]::GetFileNameWithoutExtension($sourcePath) + ".exe"
$executablePath = Join-Path $buildDirectory $executableName
$includePath = Join-Path $repoRoot "include"

& $compiler.Source -std=c++20 -Wall -Wextra -Wpedantic -I $includePath $sourcePath -o $executablePath
if ($LASTEXITCODE -ne 0) {
    throw "Compilation failed with exit code $LASTEXITCODE."
}

Write-Host "Running $executableName" -ForegroundColor Cyan
& $executablePath
exit $LASTEXITCODE

