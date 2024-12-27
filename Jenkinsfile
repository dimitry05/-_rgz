pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                script {
                    echo 'Сборка оброза...'
                    sh 'docker build -t your_image_name .'
                }
            }
        }
        stage('Deploy') {
            steps {
                script {
                    echo 'Обновление контейнера...'
                    sh 'docker-compose up -d'
                }
            }
        }
    }
}
