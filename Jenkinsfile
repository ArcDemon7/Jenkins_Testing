
pipeline {
    agent any

    environment {
        UE_PATH = "C:\\Program Files\\Epic Games\\UE_5.5"
        PROJECT_NAME = "Jenkins_Project"
        ARCHIVE_DIR = "C:\\BuildOutput"
    }

    stages {

        stage('Checkout') {
            steps {
                git branch: 'main', url: 'https://github.com/ArcDemon7/Jenkins_Testing.git'
            }
        }

        stage('Find UProject') {
            steps {
                bat '''
                for /R "%WORKSPACE%" %%f in (*.uproject) do set PROJECT=%%f
                echo Found project: %PROJECT%
                echo PROJECT=%PROJECT% > project_path.txt
                '''
            }
        }

        stage('Generate Project Files') {
            steps {
                bat '''
                set /p PROJECT=<project_path.txt

                "%UE_PATH%\\Engine\\Binaries\\DotNET\\UnrealBuildTool\\UnrealBuildTool.exe" ^
                -projectfiles ^
                -project="%PROJECT%" ^
                -progress
                '''
            }
        }

        stage('Build Editor') {
            steps {
                bat '''
                set /p PROJECT=<project_path.txt

                "%UE_PATH%\\Engine\\Build\\BatchFiles\\Build.bat" ^
                %PROJECT_NAME%Editor Win64 Development ^
                -project="%PROJECT%" ^
                -waitmutex -NoHotReload
                '''
            }
        }

        stage('Cook + Package') {
            steps {
                bat '''
                set /p PROJECT=<project_path.txt

                "%UE_PATH%\\Engine\\Build\\BatchFiles\\RunUAT.bat" ^
                BuildCookRun ^
                -project="%PROJECT%" ^
                -noP4 ^
                -platform=Win64 ^
                -clientconfig=Development ^
                -build ^
                -cook ^
                -stage ^
                -package ^
                -archive ^
                -archivedirectory="%ARCHIVE_DIR%"
                '''
            }
        }
    }

    post {
        success {
            echo "Build succeeded"
        }
        failure {
            echo "Build failed"
        }
    }
}