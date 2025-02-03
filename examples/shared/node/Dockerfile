FROM node:23.7-bullseye-slim@sha256:ddde50802a76b8ac61995c7d44d469c39e483e391cad03327065ac2e1f28abfd as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
