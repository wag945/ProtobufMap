pipeline {
    agent any
    stages {
        stage('build') {
            steps {
              echo "build step"
              sh 'printenv'
              sh 'cmake .'
            }
            steps {
              echo "test step"
            }
        }
    }
}
