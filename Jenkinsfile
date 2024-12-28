pipeline {
  agent any
  stages {
    stage('Checkout') {
      steps {
        script {
          echo 'Проверяем изменения в репозитории...'
        }
        checkout scm
      }
    }
    
    stage('Build Docker Image') {
      steps {
        script {
          echo ' Сборка Docker образа...'
          sh 'docker build -t my-app:latest .'
        }
      }
    }
    
    stage('Stop Existing Container') {
      steps {
        script {
          echo 'Если запущен существующий контейнер, то останавливаем его...'
          sh '''
          if [ "$(docker ps -q -f name=my-app-container)" ]; then
            docker stop my-app-container
          fi
          '''
        }
      }
    }
    
    stage('Remove Existing Container') {
      steps {
        script {
          echo 'Если существует контейнер, удаляем существующий контейнер...'
          sh '''
          if [ "$(docker ps -aq aq -f status=exited -f name=my-app-container)" ]; then
            docker rm my-app-container
          fi
          '''
        }
      }
    }
    
    stage('Run Docker Container') {
      steps {
        script {
          echo 'Запускаем новый контейнер...'
          sh 'docker run -d --name my-app-container my-app:latest'
        }
      }
    }
  }
  post {
    success {
      echo 'Процесс завершен успешно!'
    }
    failure {
      echo 'Произошла ошибка в процессе сборки или развертывания.'
    }
  }
}
