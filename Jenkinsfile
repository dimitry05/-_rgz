pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                script {
                    // Соберите Docker-образ
                    sh 'docker build -t your_image_name .'
                }
            }
        }
        stage('Deploy') {
            steps {
                script {
                    // Обновите контейнер
                    sh 'docker-compose up -d'
                }
            }
        }
    }
}
