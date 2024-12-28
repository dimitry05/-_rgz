# Указываем базовый образ
FROM python:3.8-slim

# Устанавливаем рабочую директорию
WORKDIR /app

# Копируем файлы в образ
COPY requirements.txt .

# Устанавливаем зависимости
RUN pip install --no-cache-dir -r requirements.txt

# Копируем остальной код приложения
COPY . .

# Указываем переменные окружения
ENV FLASK_APP=app.py
ENV FLASK_RUN_HOST=0.0.0.0

# Открываем порт
EXPOSE 5000

# Указываем команду для запуска приложения
CMD ["flask", "run"]
