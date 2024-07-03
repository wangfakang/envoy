FROM node:22.4-bullseye-slim@sha256:5e636db3e261240a86362aa7ce3bfc6bc0c65d5d38e8c3c7ad1a6471372a1f3e as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
