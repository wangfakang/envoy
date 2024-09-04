FROM node:22.8-bullseye-slim@sha256:c6e55b1a54a1626b05dfa757e8f8b0ee3c1350816d8ad022aa84a7ef4c5ed5b2 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
